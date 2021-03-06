﻿using System.Collections;
using System.Collections.Generic;
using UnityEditor.Experimental.GraphView;
using UnityEngine;

public class Enemy_Attack : MonoBehaviour
{
    private bool DAT = true;
    public Transform EnemyInstaKill;
    private float EIKRange = 0.9f;
    public int maxHealth = 100;
    [SerializeField] private string enemyRefName;
    [SerializeField] private Object enemyRef;
    public int currentHealth;
    private GameObject Player;
    public GameObject projectile;
    public float minDamage;
    public float maxDamage;
    public float projectileSpeed;
    private float shootTime;
    public float startShootTime;
    [SerializeField] private Transform pfFieldOfView;
    [SerializeField] private float fov;
    public float viewDistance;
    private FieldOfView fieldOfView;
    private Enemy_Patrol Patrol;
    public bool isIn = false;
    public bool b = true;
    Vector3 aimDir;
    private Transform Raton;
    void Start()
    {
        Raton = GameObject.Find("Raton").transform;
        enemyRef = Resources.Load(enemyRefName);
        Player = GameObject.Find("PlayerSprite");
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

        if (Player.GetComponent<recieve_Damage>().health<=0)
        {
            TakeDamage(maxHealth);
        }
      if(Mathf.Abs(Raton.transform.position.x - transform.position.x) < viewDistance && Mathf.Abs(Raton.transform.position.y - transform.position.y) < viewDistance)
        {
            gameObject.GetComponent<Enemy_Patrol>().speed = 0;
        }
        else { gameObject.GetComponent<Enemy_Patrol>().speed = gameObject.GetComponent<Enemy_Patrol>().normalSpeed; }

        if (Mathf.Abs(Player.transform.position.x - transform.position.x) < viewDistance && Mathf.Abs(Player.transform.position.y - transform.position.y) < viewDistance)
        {
            Collider2D[] hit = Physics2D.OverlapCircleAll(EnemyInstaKill.position, EIKRange);
            Vector2 dirToPlayer = (Player.transform.position - transform.position).normalized;
            float weakAngle = Vector2.Angle(-aimDir, dirToPlayer);
            foreach (Collider2D jugador in hit)
            {
                if (jugador.name == "PlayerSprite")
                {
                    if (weakAngle < fov / 2f) { isIn = true; } else { isIn = false; }
                }
            }
            
            float angle = Vector2.Angle(aimDir, dirToPlayer);
            if (angle < fov / 2f)
            {
                
                foreach(Collider2D jugador in hit)
                {
                    
                    if (jugador.name == "PlayerSprite")
                    {
                        if (b)
                        {
                            b = false;
                            Player.GetComponent<recieve_Damage>().DealDamage(Player.GetComponent<recieve_Damage>().maxHealth);
                            print("INSTAKILL ");
                        }
                    }
                }

                //Debug.Log(angle);
                if (shootTime <= 0)
                {
                    GameObject arrow = Instantiate(projectile, transform.position, Quaternion.identity);
                    Vector2 playerPos = Player.transform.position;
                    Vector2 enemyPos = transform.position;
                    Vector2 direction = dirToPlayer;
                    arrow.GetComponent<Damage>().damage = Random.Range(minDamage, maxDamage);
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
        else
        {
            isIn = false;
        }
    }
    public void TakeDamage(int damage)
    {
        currentHealth -= damage;
        if (currentHealth < 0)
        {
            /*gameObject.SetActive(false);
            Destroy(fieldOfView);
            if (b)
            {
                Respawn();
            }*/
            


            Destroy(gameObject);
        }
    }
    /*void Respawn()
    {
        GameObject enemyClone = (GameObject)Instantiate(enemyRef);
        enemyClone.transform.position = transform.position;
        Destroy(gameObject);
    }*/
    private void OnDrawGizmosSelected()
    {
        Gizmos.DrawWireSphere(EnemyInstaKill.position, EIKRange);
    }

    private void OnDestroy()
    {

        Destroy(fieldOfView);
    }
}
