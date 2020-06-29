using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Chest : MonoBehaviour, Interactable
{
    [SerializeField]

    private SpriteRenderer spriteRenderer;
    [SerializeField]

    private Sprite openSprite, closeSprite;

    [SerializeField] private ParticleSystem pfparticleSystem;


    bool isOpen;

    private void Start()
    {
        isOpen = false;
    }

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
        if (!isOpen)
        {
            spriteRenderer.sprite = openSprite;

            Transform particleTransform = pfparticleSystem.transform;
            particleTransform.position = transform.position;
            ParticleSystem coins = Instantiate(pfparticleSystem, particleTransform);
            coins.Play(true);

            isOpen = true;
        }

    }
    public void StopInteract()
    {
        
    }
}
