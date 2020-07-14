using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy_Patrol : MonoBehaviour
{
    public float speed;//Velocidad de movimiento
    private float waitTime; //Tienpo de espera en cada punto
    public float startWaitTime; //Tiempo maximo de espera
    public Transform[] moveSpots;// Lista de puntos de vigilancia 
    private int spot; //Iterador de la lista
    private Transform Player;
    private Vector3 lastMoveDir;
    private Vector3 spotDir;


    void Start()
    {
        spot = 0;
        waitTime = startWaitTime;
        spotDir = (moveSpots[spot].position - transform.position).normalized;
        lastMoveDir = spotDir;
        Player = GameObject.Find("PlayerSprite").transform;
        Client.instance.SendData("CREATE|ENEMY|"+gameObject.name +"|X:" + Math.Round(transform.position.x) + ",Y:" + Math.Round(transform.position.y));
    }


    void Update()
    {
        transform.position = Vector2.MoveTowards(transform.position, moveSpots[spot].position, speed * Time.deltaTime);//Posiciona el enemigo en el punto
        
        if (Vector2.Distance(transform.position,moveSpots[spot].position)<0.2f)// verifica que haya llegado
        {
            if (waitTime<=0)//Verifica que sea tiempo de moverse
            {
                if (spot == moveSpots.Length - 1)//Verifica que el iterador no sobrepase la lista
                {
                    spot = 0;
                }
                else { spot += 1; }
                waitTime = startWaitTime;

                spotDir = (moveSpots[spot].position - transform.position).normalized;
                lastMoveDir = spotDir;
            }
            else
            {
                waitTime -= Time.deltaTime;
            }
        }

        Client.instance.SendData("UPDATE|ENEMY|" + gameObject.name + "|X:" + Math.Round(transform.position.x) + ",Y:" + Math.Round(transform.position.y));
        

    }

    public  Vector3 GetAimDir()
    {
        return lastMoveDir;
    }

}
