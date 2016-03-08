using UnityEngine;
using System.Collections;

public class FollowingCamera : MonoBehaviour {

    public GameObject target;
	void Start () {
        
	}
	
	// Update is called once per frame
	void Update () {
        int DistanceAway = 10;
        Vector3 PlayerPOS = target.transform.transform.position;
        this.transform.position = new Vector3(PlayerPOS.x, PlayerPOS.y, PlayerPOS.z - DistanceAway);
    }
}
