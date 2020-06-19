﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy_Patrol : MonoBehaviour
{
    public float speed;//Velocidad de movimiento
    private float waitTime; //Tienpo de espera en cada punto
    public float startWaitTime; //Tiempo maximo de espera
    public Transform[] moveSpots;// Lista de puntos de vigilancia 
    private int spot; //Iterador de la lista
    public Transform Player;

    void Start()
    {
        spot = 0;
        waitTime = startWaitTime;
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
            }else
            {
                waitTime -= Time.deltaTime;
            }
        }
    }
}
