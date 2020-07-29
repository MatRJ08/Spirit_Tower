using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Chuchu : MonoBehaviour
{
    public Transform Player;
    public Transform hitArea;
    void Start()
    {
        
    }

    void Update()
    {
        Bresenham(  (int)Math.Round(transform.position.x), (int)Math.Round(transform.position.y),
                    (int)Math.Round(Player.position.x), (int)Math.Round(Player.position.x));
    }
    private void Bresenham(int x0, int y0, int x1, int y1)
    {
        bool steep = Math.Abs(y1 - y0) > Math.Abs(x1 - x0);
        if (steep)
        {
            int t;
            t = x0; // swap x0 and y0
            x0 = y0;
            y0 = t;
            t = x1; // swap x1 and y1
            x1 = y1;
            y1 = t;
        }
        if (x0 > x1)
        {
            int t;
            t = x0; // swap x0 and x1
            x0 = x1;
            x1 = t;
            t = y0; // swap y0 and y1
            y0 = y1;
            y1 = t;
        }
        int dx = x1 - x0;
        int dy = Math.Abs(y1 - y0);
        int error = dx / 2;
        int ystep = (y0 < y1) ? 1 : -1;
        int y = y0;
        for (int x = x0; x <= x1; x++)
        {
            Vector2 destPos=new Vector2((steep ? y : x), (steep ? x : y));
            transform.position = Vector2.MoveTowards(transform.position, destPos, 0.5f * Time.deltaTime);
                
            error = error - dy;
            if (error < 0)
            {
                y += ystep;
                error += dx;
            }
        }
    }
    private void OnDrawGizmosSelected()
    {
        Gizmos.DrawWireSphere(hitArea.position, 1.5f);
    }
}

