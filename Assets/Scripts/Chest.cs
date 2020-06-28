using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Chest : MonoBehaviour, Interactable
{
    [SerializeField]

    private SpriteRenderer spriteRenderer;
    [SerializeField]

    private Sprite openSprite, closeSprite;
    bool isOpen;
    public void OnTriggerEnter2D (Collider2D collision)
    {
        if (collision.tag == "Player")
        {
            Interact();
        }
    }
    public void OnTriggerExit2D(Collider2D collision)
    {
        if (collision.tag == "Player")
        {
            StopInteract();
        }
    }
    public void Interact()
    {
        if (isOpen)
        {
            StopInteract();
        }
        else
        {
            isOpen = true;
            spriteRenderer.sprite = openSprite;
        }

    }
    public void StopInteract()
    {
        spriteRenderer.sprite = closeSprite;
    }
}
