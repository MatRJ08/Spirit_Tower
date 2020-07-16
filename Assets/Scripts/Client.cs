using System;
using System.Collections;
using System.Collections.Generic;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Client : MonoBehaviour
{
    //[SerializeField] 
    private Transform[] enemies=new Transform[3];
    private GameObject player;
    private TcpClient socket;
    private Thread clientReceiveThread;
    private string delimiter = "~";
    private LinkedList<string> incomingQueue = new LinkedList<string>();
    private float[] DAT = new float[3];
    public static Client instance { get; private set; }

    private void Awake()
    {
        DontDestroyOnLoad(gameObject);
        if (instance == null)
        {
            instance = this;
            DontDestroyOnLoad(gameObject);
        }
        else
        {
            Destroy(gameObject);
        }
    }


    // Start is called before the first frame update
    void Start()
    {
        
        ConnectToTcpServer();
    }

    // Update is called once per frame
    void Update()
    {
        if (player == null)
        {
            print("enemies");
            print("SCENE: "+ SceneManager.GetActiveScene().name);
            switch (SceneManager.GetActiveScene().name)
            {
                case "Dungeon1":
                    print(enemies[0] );
                    enemies[0] = GameObject.Find("Gray_Enemy1").transform;
                    enemies[1] = GameObject.Find("Gray_Enemy2").transform;
                    enemies[2] = GameObject.Find("Gray_Enemy3").transform;
                    break;
                case "Dungeon2":
                    enemies[0] = GameObject.Find("Red_Enemy1").transform;
                    enemies[1] = GameObject.Find("Red_Enemy2").transform;
                    enemies[2] = GameObject.Find("Red_Enemy3").transform;
                    break;
                case "Dungeon3":
                    enemies[0] = GameObject.Find("Blue_Enemy1").transform;
                    enemies[1] = GameObject.Find("Blue_Enemy2").transform;
                    enemies[2] = GameObject.Find("Blue_Enemy3").transform;
                    break;
                case "Dungeon4":
                    enemies[0] = GameObject.Find("Red_Enemy1").transform;
                    enemies[1] = GameObject.Find("Red_Enemy2").transform;
                    enemies[2] = GameObject.Find("Red_Enemy3").transform;
                    break;

            }
            
        }
        player = GameObject.Find("PlayerSprite");
        handleIncomingData();
    }

    // Inicializar thread para recibir mensajes del servidor
    private void ConnectToTcpServer()
    {
        try
        {
            clientReceiveThread = new Thread(new ThreadStart(ListenForData));
            clientReceiveThread.IsBackground = true;
            clientReceiveThread.Start();
        }
        catch (Exception e)
        {
            Debug.Log("On client connect exception " + e);
        }
    }

    // Escuchar mensajes del servidor
    private void ListenForData()
    {
        try
        {
            socket = new TcpClient("localhost", 27015);
            Byte[] bytes = new byte[1024];
            while (true)
            {
                using (NetworkStream stream = socket.GetStream())
                {
                    int length;
                    while ((length = stream.Read(bytes, 0, bytes.Length)) != 0)
                    {
                        var incomingData = new byte[length];
                        Array.Copy(bytes, 0, incomingData, 0, length);


                        string serverMessage = Encoding.ASCII.GetString(incomingData);
                        incomingQueue.Queue(serverMessage);
                        //handleIncomingData(serverMessage);
                    }
                }
            }
        }
        catch (SocketException socketException)
        {
            Debug.Log("Socket exception: " + socketException);
        }
    }

    // Envia mensaje al servidor
    public void SendData(string data)
    {
        
        if (socket == null)
        {
            return;
        }
        try
        {
            NetworkStream stream = socket.GetStream();
            if (stream.CanWrite)
            {
                byte[] clientMessageAsByteArray = Encoding.ASCII.GetBytes(data + delimiter);


                stream.Write(clientMessageAsByteArray, 0, clientMessageAsByteArray.Length);
                // Debug.Log("Client sent his message - should be received by server");
                stream.Flush();
            }
        }
        catch (SocketException socketException)
        {
            Debug.Log("Socket exception: " + socketException);
        }
    }

    void handleIncomingData()
    {

        if (incomingQueue.Peek() == null)
        {
            return;
        }
        else
        {
            string message = incomingQueue.Pop();



            string[] dataToHandle = message.Split('|');


            if (dataToHandle[0] == "DAT")
            {
                
                if(dataToHandle[1]== "V_RUTA")
                {
                    if (dataToHandle[2] == "0")
                    {
                        decimal ruta;
                        decimal.TryParse(dataToHandle[3], out ruta);
                        ruta = Math.Round(ruta, 2);
                        enemies[0].GetComponent<Enemy_Attack>().GetComponent<Enemy_Patrol>().speed= Convert.ToSingle(ruta);
                        
                    }
                    if (dataToHandle[2] == "1")
                    {
                        decimal ruta;
                        decimal.TryParse(dataToHandle[3], out ruta);
                        ruta = Math.Round(ruta, 2);
                        enemies[1].GetComponent<Enemy_Attack>().GetComponent<Enemy_Patrol>().speed = Convert.ToSingle(ruta);
                    }
                    if (dataToHandle[2] == "2")
                    {
                        decimal ruta;
                        decimal.TryParse(dataToHandle[3], out ruta);
                        ruta = Math.Round(ruta, 2);
                        enemies[2].GetComponent<Enemy_Attack>().GetComponent<Enemy_Patrol>().speed = Convert.ToSingle(ruta);
                    }


                }
                if(dataToHandle[1] == "V_PER")
                {
                    if (dataToHandle[2] == "0")
                    {
                        decimal ruta;
                        decimal.TryParse(dataToHandle[3], out ruta);
                        ruta = Math.Round(ruta, 2);
                        enemies[0].GetComponent<Enemy_Attack>().GetComponent<Enemy_Patrol>().runSpeed = Convert.ToSingle(ruta);
                    }
                    if (dataToHandle[2] == "1")
                    {
                        decimal ruta;
                        decimal.TryParse(dataToHandle[3], out ruta);
                        ruta = Math.Round(ruta, 2);
                        enemies[1].GetComponent<Enemy_Attack>().GetComponent<Enemy_Patrol>().runSpeed = Convert.ToSingle(ruta);
                    }
                    if (dataToHandle[2] == "2")
                    {
                        decimal ruta;
                        decimal.TryParse(dataToHandle[3], out ruta);
                        ruta = Math.Round(ruta, 2);
                        enemies[2].GetComponent<Enemy_Attack>().GetComponent<Enemy_Patrol>().runSpeed = Convert.ToSingle(ruta);
                    }

                }
                if(dataToHandle[1] == "RADIO")
                {
                    if (dataToHandle[2] == "0")
                    {
                        decimal ruta;
                        decimal.TryParse(dataToHandle[3], out ruta);
                        ruta = Math.Round(ruta, 2);
                        enemies[0].GetComponent<Enemy_Attack>().GetComponent<Enemy_Attack>().viewDistance = Convert.ToSingle(ruta);
                    }
                    if (dataToHandle[2] == "1")
                    {
                        decimal ruta;
                        decimal.TryParse(dataToHandle[3], out ruta);
                        ruta = Math.Round(ruta, 2);
                        enemies[1].GetComponent<Enemy_Attack>().GetComponent<Enemy_Attack>().viewDistance = Convert.ToSingle(ruta);
                    }
                    if (dataToHandle[2] == "2")
                    {
                        decimal ruta;
                        decimal.TryParse(dataToHandle[3], out ruta);
                        ruta = Math.Round(ruta, 2);
                        enemies[2].GetComponent<Enemy_Attack>().GetComponent<Enemy_Attack>().viewDistance = Convert.ToSingle(ruta);
                    }
                }

            }
            if (dataToHandle[0] == "PLAYER")
            {

                if (dataToHandle[1] == "rHEALTH")
                {
                    int Damage = 0;
                    if (Int32.TryParse(dataToHandle[2], out Damage))
                    {
                        //Debug.Log("Damage taken, new health should be " + player.GetComponent<recieve_Damage>().health-Dama);
                        player.GetComponent<recieve_Damage>().ReduceHealth(Convert.ToSingle(Damage));
                    }
                    else
                    {
                        Debug.Log("Error in message received");
                    }
                }
            }
        }
    }
    
}