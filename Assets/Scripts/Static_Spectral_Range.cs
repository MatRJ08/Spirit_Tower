using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Static_Spectral_Range : MonoBehaviour
{
    [SerializeField] private float fov;
    [SerializeField] private float viewDistance;
    [SerializeField] private float minRotation;
    [SerializeField] private float maxRotation;
    [SerializeField] private Transform pfFieldOfView;
    [SerializeField]private float incrementAngleSpeed;
    private FieldOfView fieldOfView;
    private float Angle;
    private bool needToDecrease;

    void Start()
    {
        fieldOfView = Instantiate(pfFieldOfView, null).GetComponent<FieldOfView>();
        fieldOfView.SetFov(fov);
        fieldOfView.SetViewDistance(viewDistance);
        Angle = minRotation;
        fieldOfView.SetOrigin(transform.position);
    }

    // Update is called once per frame
    private void FixedUpdate()
    {
        if (!needToDecrease)
        {
            fieldOfView.SetAimDirection(Angle);
            Angle += incrementAngleSpeed;
           
            if (Angle >= maxRotation && maxRotation != 360)
            {
                needToDecrease = true;
            }
            else if (Angle >= maxRotation)
            {
                Angle = 0f;
            }
        }
        else if (needToDecrease)
        {
            fieldOfView.SetAimDirection(Angle);
            Angle -= incrementAngleSpeed;
            if (Angle <= minRotation)
            {
                needToDecrease = false;
            }
        }
    }
}
