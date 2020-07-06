using System.Collections;
using System.Collections.Generic;
using System;
using UnityEngine;
using UnityEngine.SceneManagement;

public class recieve_Damage : MonoBehaviour
{
    public float health;
    public float maxHealth;
    void Start()
    {
        health = maxHealth;
        
    }
    public void DealDamage(float damage)
    {

       //print("damage: " + damage);
        //Client.instance.SendData("REQUEST|PLAYER|DAMAGE:" + Math.Round(damage));

       
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
            SceneManager.LoadScene(SceneManager.GetActiveScene().name);
        }
    }
}
