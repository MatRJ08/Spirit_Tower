using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Player_Movement : MonoBehaviour
{
    public float moveSpeed = 5f;
    public Transform movePoint;
    public Animator animator;
    Vector2 movement;
    public int Piso;

    public LayerMask stopMovement;

    private void Start()
    {
        print("Piso "+Piso);
        
        movePoint.parent = null;

    }

    private void Update()
    {
        
        switch (SceneManager.GetActiveScene().name)
        {
            case "Dungeon1":
                Piso = 0;
                break;
            case "Dungeon2":
                Piso = 1;
                break;
            case "Dungeon3":
                Piso = 2;
                break;
            case "Dungeon4":
                Piso = 3;
                break;

        }
        movement.x = Input.GetAxisRaw("Horizontal");
        movement.y = Input.GetAxisRaw("Vertical");
        animator.SetFloat("Horizontal", movement.x);
        animator.SetFloat("Vertical", movement.y);
        animator.SetFloat("Speed", movement.sqrMagnitude);


        Client.instance.SendData("UPDATE|PLAYER|X:" + Math.Round(transform.position.x) + ",Y:" + Math.Round(transform.position.y) + ";HP:" + Math.Round(GetComponent<recieve_Damage>().health));
        
       
    }
    public int getPiso()
    {
        return Piso;
    }
    private void FixedUpdate()
    {
        Client.instance.SendData("PISO|"+ Piso);
        
        transform.position = Vector3.MoveTowards(transform.position, movePoint.position, moveSpeed * Time.deltaTime);
        if (Vector3.Distance(transform.position, movePoint.position) <= .05f)
        {
            if (Mathf.Abs(movement.x) == 1f)
            {
                Vector3 newPos = new Vector3(movement.x, 0f, 0f);
                if (!Physics2D.OverlapCircle(movePoint.position + newPos, .2f, stopMovement))
                    movePoint.position += newPos;
                else
                    movePoint.position = transform.position;

            }
            if (Mathf.Abs(movement.y) == 1f)
            {
                Vector3 newPos = new Vector3(0f, movement.y, 0f);
                if (!Physics2D.OverlapCircle(movePoint.position + newPos, .2f, stopMovement))
                    movePoint.position += newPos;
                else
                    movePoint.position = transform.position;

            }
        }
    }

}
