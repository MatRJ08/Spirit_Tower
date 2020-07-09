using System.Collections;
using System.Collections.Generic;
using System;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class recieve_Damage : MonoBehaviour
{
    public Transform Player;
    public Transform movePoint;
    public Transform[] enemies;
    public float health;
    public float maxHealth;
    private int numHearts= 5;
    public Image[] hearts;
    public Sprite full;
    public Sprite empty;
    private Vector3 InitPos;

    void Start()
    {
        movePoint.parent = null;
        InitPos = Player.position;

        health = maxHealth;
    }
   
    public void DealDamage(float damage)
    {
        // Client.instance.SendData("REQUEST|PLAYER|DAMAGE:" + Math.Round(damage));
        health -= damage;
        CheckDeath();
    }
    void CheckOverHeal()
    {
        if(health> maxHealth)
        {
            health = maxHealth;
        }
    }

    void CangeHearts()
    {
        for (int i = 1; i < hearts.Length; i++)
        {
            if (i < numHearts)
            {
                hearts[i].sprite = full;
            }
            else
            {
                hearts[i].sprite = empty;
            }
            
        }
    }

    void CheckDeath()
    {
        if (health <= 0)
        {
            health = 0;
            numHearts -= 1;
            if (numHearts == 0)
            {
                CangeHearts();
                print("DEST");
                Destroy(gameObject);
            }
            else
            {                
                
                movePoint.position=InitPos;
                Player.position = InitPos;
                health = maxHealth;
                CangeHearts();
                ResetEnemies();
                print("RESPAWN");
                
            }
        }
    }
    void ResetEnemies()
    {
        for (int i = 0; i < enemies.Length; i++)
        {
            
            enemies[i].position = enemies[i].GetComponent<Enemy_Patrol>().moveSpots[0].position;
            enemies[i].GetComponent<Enemy_Attack>().currentHealth = enemies[i].GetComponent<Enemy_Attack>().maxHealth;
        }
    }
}
