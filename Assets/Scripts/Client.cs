using System;
using System.Collections;
using System.Collections.Generic;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using UnityEngine;

public class Client : MonoBehaviour
{
    public GameObject player;
    private TcpClient socket;
    private Thread clientReceiveThread;
    private string delimiter = "~";
    private LinkedList<string> incomingQueue = new LinkedList<string>();
    public static Client instance { get; private set; }

    private void Awake()
    {
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
                byte[] clientMessageAsByteArray = Encoding.ASCII.GetBytes(data+delimiter);


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


            if (dataToHandle[0] == "PLAYER")
            {

                if (dataToHandle[1] == "rHEALTH")
                {
                    int newHealth = 0;
                    if (Int32.TryParse(dataToHandle[2], out newHealth))
                    {
                        Debug.Log("Damage taken, new health should be " + newHealth);
                        player.GetComponent<recieve_Damage>().ReduceHealth(Convert.ToSingle(newHealth));
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
