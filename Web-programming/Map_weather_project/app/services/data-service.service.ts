import { Injectable } from '@angular/core';
import { BehaviorSubject } from 'rxjs/BehaviorSubject';

@Injectable({
  providedIn: 'root'
})
export class DataServiceService {

  private latitudeSource = new BehaviorSubject(61);
  currentLatitude = this.latitudeSource.asObservable();

  private longitudeSource = new BehaviorSubject(22);
  currentLongitude = this.longitudeSource.asObservable();

  constructor() {}

  changeLatitude(lat: number){
    this.latitudeSource.next(lat)
  }

  changeLongitude(lng: number){
    this.longitudeSource.next(lng)
  }

}
