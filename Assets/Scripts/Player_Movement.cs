using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player_Movement : MonoBehaviour
{

    public float moveSpeed = 5f;
    public Rigidbody2D rb;
    public Animator animator;

    Vector2 movement;
    // Update is called once per frame
    void Update()
    {
        movement.x = Input.GetAxisRaw("Horizontal");
        movement.y = Input.GetAxisRaw("Vertical");

        animator.SetFloat("Horizontal", movement.x);
        animator.SetFloat("Vertical", movement.y);
        animator.SetFloat("Speed", movement.sqrMagnitude);
    }

    void FixedUpdate()
    {
        //gameObject.transform.Translate(movement.x + moveSpeed, movement.y + moveSpeed, 0.0f);
        if (Input.GetKey("d") || Input.GetKey("right"))
        {
            gameObject.transform.position = new Vector2(gameObject.transform.position.x + moveSpeed * Time.deltaTime, gameObject.transform.position.y);
        }
        else if (Input.GetKey("a") || Input.GetKey("left"))
        {
            gameObject.transform.position = new Vector2(gameObject.transform.position.x - moveSpeed * Time.deltaTime, gameObject.transform.position.y);
        }
        else if (Input.GetKey("w") || Input.GetKey("up"))
        {
            gameObject.transform.position = new Vector2(gameObject.transform.position.x, gameObject.transform.position.y + moveSpeed * Time.deltaTime);
        }
        else if (Input.GetKey("s") || Input.GetKey("down"))
        {
            gameObject.transform.position = new Vector2(gameObject.transform.position.x, gameObject.transform.position.y - moveSpeed * Time.deltaTime);
        }
    }

    void OnCollisionEnter2D(Collision2D col)
    {
        Debug.Log("OnCollisionEnter2D");
    }
}
