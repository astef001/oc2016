using UnityEngine;
using System.Collections;

public class Breaking : MonoBehaviour {

    Rigidbody rg;
	void Start () {
        rg = gameObject.GetComponent<Rigidbody>();
        rg.AddForce(new Vector3(0, 0, 2), ForceMode.Acceleration);
	}

    void FixedUpdate()
    {
        float i = (float)1;
        if (rg.position.z >= GameObject.Find("Cube").GetComponent<Rigidbody>().position.z - 15)
        {
            if ((int)rg.velocity.z > 0)
                rg.AddForce(new Vector3(0, 0, -1), ForceMode.Acceleration);
            else
            {
                rg.AddForce(new Vector3(0, 0, 0), ForceMode.Acceleration);
                rg.velocity = new Vector3(0, 0, 0);
                rg.freezeRotation= true;
            }

        }
        else
            rg.AddForce(new Vector3(0, 0, 2), ForceMode.Acceleration);
        
    }
            
}
