using System.Collections;
using System.Collections.Generic;
using UnityEditor.Experimental.GraphView;
using UnityEngine;

public class chuchuAtack : MonoBehaviour
{
    public Transform hitArea;
    private float EIKRange = 0.9f;
    public int maxHealth = 100;
    [SerializeField] private string enemyRefName;
    [SerializeField] private Object enemyRef;
    public int currentHealth;
    private GameObject Player;
    private float attackTime = 1f;
    public Vector2 initPos;
    void Start()
    {
        initPos = transform.position;
        enemyRef = Resources.Load(enemyRefName);
        Player = GameObject.Find("PlayerSprite");
        currentHealth = maxHealth;

    }
    void Update()
    {
        if (Player.GetComponent<recieve_Damage>().health <= 0)
        {
            TakeDamage(maxHealth);
        }
        Collider2D[] hit = Physics2D.OverlapCircleAll(hitArea.position, 1.5f);
        if (attackTime <= 0)
        {
            foreach (var item in hit)
            {
                if (item.name == "PlayerSprite")
                {
                    print("CHU ATTACK");
                    Player.GetComponent<recieve_Damage>().DealDamage(1f);
                }
            }
        }
        else { attackTime -= Time.deltaTime; }
    }
    public void TakeDamage(int damage)
    {
        currentHealth -= damage;
        if (currentHealth < 0)
        {
            print("Chu respawn");
            Destroy(gameObject);
        }
    }
    private void OnDrawGizmosSelected()
    {
        Gizmos.DrawWireSphere(hitArea.position, EIKRange);
    }

}
