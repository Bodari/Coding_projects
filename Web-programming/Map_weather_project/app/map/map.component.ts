import { Component, OnInit } from '@angular/core';
import { MouseEvent } from '@agm/core';

import { DataServiceService } from "../services/data-service.service";

@Component({
  selector: 'app-map',
  templateUrl: './map.component.html',
  styleUrls: ['./map.component.css']
})
export class MapComponent implements OnInit {

    lat = 61;
    lng = 22;
    zoom = 7;

    constructor(private data: DataServiceService) { }

    ngOnInit() {
    }

    mapClicked($event: MouseEvent) {
      this.lat = $event.coords.lat;
      this.data.changeLatitude(this.lat)

      this.lng = $event.coords.lng;
      this.data.changeLongitude(this.lng)
    }

}
