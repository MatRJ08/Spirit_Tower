using System.Collections;
using System.Collections.Generic;
using System;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class recieve_Damage : MonoBehaviour
{
    public Transform[] enemies;
    public float health;
    public float maxHealth;
    private int numHearts= 5;
    public Image[] hearts;
    public Sprite full;
    public Sprite empty;

    void Start()
    {
        print("NUM start: " + numHearts);
        health = maxHealth;
    }
   
    public void DealDamage(float damage)
    {
        
     
        for (int i = 0; i <numHearts; i++)
        {
            if (i < numHearts)
            {
                hearts[i].enabled = true;
            }
            else
            {
                hearts[i].enabled = false;
            }
        }

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

    void CheckDeath()
    {
        if (health <= 0)
        {
            numHearts -= 1;
            print("NUM death: " + numHearts);
            if (numHearts == 0)
            {
                print("DEST");
                Destroy(gameObject);
            }
            else
            {
                print("SCENE");
                SceneManager.LoadScene(SceneManager.GetActiveScene().name);

               /* for (int i = 0; i < enemies.Length; i++)
                {
                    enemies[i].position=GetComponent
                }*/
            }
        }
    }
}
