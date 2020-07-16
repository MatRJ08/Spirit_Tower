using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class NextLvl : MonoBehaviour
{
    private void OnTriggerEnter2D(Collider2D collision)
    {
        print("COLLISION: "+collision.name);
        print("SCENE: " + SceneManager.GetActiveScene().name);
        if (collision.name == "PlayerSprite")
        {
            switch (SceneManager.GetActiveScene().name)
            {
                case "Dungeon1":
                    SceneManager.LoadScene("Dungeon2", LoadSceneMode.Single);
                    break;
                case "Dungeon2":
                    SceneManager.LoadScene("Dungeon3", LoadSceneMode.Single);
                    break;
                case "Dungeon3":
                    SceneManager.LoadScene("Dungeon4", LoadSceneMode.Single);
                    break;
                case "Dungeon4":
                    SceneManager.LoadScene("Dungeon5", LoadSceneMode.Single);
                    break;

            }
        }
    }
}
