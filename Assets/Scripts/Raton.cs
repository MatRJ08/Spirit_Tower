using System.Collections;
using System.Collections.Generic;
using System.Threading;
using UnityEngine;

public class Raton : MonoBehaviour
{
    private float waitTime=1f;
    public Transform[] ratonSpots;
    int i;
    int ant;
    Vector2 RanPos;
    // Start is called before the first frame update
    void Start()
    {
        i = Random.Range(0, ratonSpots.Length - 1);
        
    }
    private void OnCollisionEnter2D(Collision2D collision)
    {
        print("PEGA");
        transform.position = Vector2.MoveTowards(transform.position, ratonSpots[ant].position, 5f * Time.deltaTime);
    }
    // Update is called once per frame
    void Update()
    {
        transform.position = Vector2.MoveTowards(transform.position, ratonSpots[i].position, 5f * Time.deltaTime);
        
        if (Vector2.Distance(transform.position, ratonSpots[i].position) < 3.5f)// verifica que haya llegado
        {

            if (waitTime <= 0)
            {
                i = Random.Range(0, ratonSpots.Length - 1);
                RanPos = new Vector2(ratonSpots[i].position.x , ratonSpots[i].position.y);
                waitTime = 2f;
                ant = i;
            }
            else { waitTime -= Time.deltaTime; }
        }
    }

    
}
