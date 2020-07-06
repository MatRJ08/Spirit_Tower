using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player_Attack : MonoBehaviour
{
    public Transform attackPoint;
    public float attackRange = 0.5f;
    public LayerMask enemyLayers;
    public int attackDamage = 10;
    public Animator animator;
  
    public Transform[] enemies;
    private Collider2D[] hitEnemies;

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            Attack();
        }

    }
    void Attack()
    {
       
        animator.SetTrigger("Attack");

        hitEnemies = Physics2D.OverlapCircleAll(attackPoint.position, attackRange, enemyLayers);
        foreach (Collider2D enemy in hitEnemies)
        {
            print(enemy.name + " IS IN: " + enemy.GetComponent<Enemy_Attack>().isIn);
            if (enemy.GetComponent<Enemy_Attack>().isIn)
            {
                
                enemy.GetComponent<Enemy_Attack>().TakeDamage(attackDamage);
            }
            else
            {
                enemy.GetComponent<Enemy_Attack>().TakeDamage(enemy.GetComponent<Enemy_Attack>().maxHealth);
            }
        }
    }

    private void OnDrawGizmosSelected()
    {
        Gizmos.DrawWireSphere(attackPoint.position, attackRange);
    }
}
