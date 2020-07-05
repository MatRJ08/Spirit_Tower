﻿using System.Collections;
using System.Collections.Generic;
using UnityEditor.Experimental.GraphView;
using UnityEngine;

public class Enemy_Attack : MonoBehaviour
{
    public int maxHealth = 100;
    private int currentHealth;
    public GameObject Player;
    public GameObject projectile;
    public float minDamage;
    public float maxDamage;
    public float projectileSpeed;
    private float shootTime;
    public float startShootTime;
    [SerializeField] private Transform pfFieldOfView;
    [SerializeField] private float fov;
    [SerializeField] private float viewDistance;
    private FieldOfView fieldOfView;
    private Enemy_Patrol Patrol;

    Vector3 aimDir;
    void Start()
    {
        currentHealth = maxHealth;
        shootTime = startShootTime;
        fieldOfView = Instantiate(pfFieldOfView, null).GetComponent<FieldOfView>();
        fieldOfView.SetFov(fov);
        fieldOfView.SetViewDistance(viewDistance);
        Patrol = GetComponent<Enemy_Patrol>();

    }
    void Update()
    {

        aimDir = Patrol.GetAimDir();
        fieldOfView.SetOrigin(transform.position);
        fieldOfView.SetAimDirection(aimDir);

        if (Mathf.Abs(Player.transform.position.x - transform.position.x) < viewDistance && Mathf.Abs(Player.transform.position.y - transform.position.y) < viewDistance)
        {
            //Debug.Log(Player.transform.position.x - transform.position.x);
            Vector2 dirToPlayer = (Player.transform.position - transform.position).normalized;

            //Debug.Log(fov/2f);
            float angle = Vector2.Angle(aimDir, dirToPlayer);
            if (angle < fov / 2f)
            {
                //Debug.Log(angle);
                if (shootTime <= 0)
                {
                    GameObject arrow = Instantiate(projectile, transform.position, Quaternion.identity);
                    Vector2 playerPos = Player.transform.position;
                    Vector2 enemyPos = transform.position;
                    Vector2 direction = dirToPlayer;
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

    public void TakeDamage(int damage)
    {
        Debug.Log("damage: " + damage);
        currentHealth -= damage;
        Debug.Log("health " + currentHealth);
        if (currentHealth < 0)
        {
            Destroy(fieldOfView);
            Destroy(gameObject);
        }
    }
}
