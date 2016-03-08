using UnityEngine;
using System.Collections;

public class SphereVelocity : MonoBehaviour {

    private double speed;
    Rigidbody rg;
    private float pos;
    void LateUpdate()
    {
        rg = this.gameObject.GetComponent<Rigidbody>();
        speed = rg.velocity.magnitude * 2.37;
        pos = rg.position.z;
    }

    void OnGUI()
    {
        GUI.Box(new Rect(10, 10, 100, 90), "m/s:");

        GUI.Label(new Rect(20, 40, 80, 20), speed.ToString());

        GUI.Box(new Rect(110, 10, 100, 90), "pos:");

        GUI.Label(new Rect(115, 50, 80, 20), pos.ToString());
        
    }
}
