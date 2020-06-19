using System.Collections;
using System.Collections.Generic;
using UnityEditor.Experimental.GraphView;
using UnityEngine;

public class Enemy_Attack : MonoBehaviour
{
    public GameObject Player;
    public GameObject projectile;
    public float minDamage;
    public float maxDamage;
    public float projectileSpeed;
    private float shootTime; 
    public float startShootTime;

    void Start()
    {
        shootTime = startShootTime;
    }
    void Update()
    {
        if (Player.transform.position.x - transform.position.x < 3.5f && Player.transform.position.y - transform.position.y < 3.5f)
        {
            if (shootTime <= 0)
            {
                GameObject arrow = Instantiate(projectile, transform.position, Quaternion.identity);
                Vector2 playerPos = Player.transform.position;
                Vector2 enemyPos = transform.position;
                Vector2 direction = (playerPos - enemyPos).normalized;
                arrow.GetComponent<Rigidbody2D>().velocity = direction * projectileSpeed;
                arrow.GetComponent<Damage>().damage = Random.Range(minDamage, maxDamage);
                shootTime = startShootTime;
            }
            else
            {
                shootTime -= Time.deltaTime;
            }
        }

    }
}
