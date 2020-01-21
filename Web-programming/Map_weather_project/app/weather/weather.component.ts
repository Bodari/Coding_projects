import { Component, OnInit, DoCheck } from '@angular/core';
import { HttpClient } from '@angular/common/http';

import { DataServiceService } from "../services/data-service.service";

@Component({
  selector: 'app-weather',
  templateUrl: './weather.component.html',
  styleUrls: ['./weather.component.css']
})
export class WeatherComponent implements OnInit, DoCheck {

  //lat = 61.503354379993155;
  //lng = 23.807852053835894;

  oldLat;
  oldLng;
  lat;
  lng;

  city: string;
  temp: number;

  ouluTemp: number;
  rovaniemiTemp: number;
  tampereTemp: number;
  helsinkiTemp: number;

  searchCity: string;
  searchCityTemp: number;

  disabledForecastButton: boolean;

  constructor(private data: DataServiceService, private http: HttpClient) {}

  ngOnInit() {
    this.data.currentLatitude.subscribe(lat => this.lat = lat)
    this.data.currentLongitude.subscribe(lng => this.lng = lng)
    this.loadWeatherData();
    this.loadOulu();
    this.loadRovaniemi();
    this.loadTampere();
    this.loadHelsinki();
  }

  ngDoCheck(){
    if (this.oldLat !== this.lat) {
          this.loadWeatherData();
          this.oldLat = this.lat;
    }

  }

  loadWeatherData(){
    let url = 'http://api.openweathermap.org/data/2.5/weather?'
            + 'lat=' + this.lat
            + '&lon=' + this.lng
            + '&units=metric'
            + '&lang=en'
            + ''; // Put your API key here!

    this.http
           .get(url)
           .subscribe((weatherData: any) => {
           console.log(weatherData);
           this.city = weatherData.name;
           this.temp = weatherData.main.temp;
      });
  }

  loadOulu(){
    let url = 'http://api.openweathermap.org/data/2.5/weather?q=Oulu'
            + '&units=metric'
            + '&lang=en'
            + ''; // Put your API key here!

    this.http
           .get(url)
           .subscribe((weatherData: any) => {
           console.log(weatherData);
           this.ouluTemp = weatherData.main.temp;
  });
  }

  loadRovaniemi(){
    let url = 'http://api.openweathermap.org/data/2.5/weather?q=Rovaniemi'
            + '&units=metric'
            + '&lang=en'
            + ''; // Put your API key here!

    this.http
           .get(url)
           .subscribe((weatherData: any) => {
           console.log(weatherData);
           this.rovaniemiTemp = weatherData.main.temp;
  });
  }

  loadTampere(){
    let url = 'http://api.openweathermap.org/data/2.5/weather?q=Tampere'
            + '&units=metric'
            + '&lang=en'
            + ''; // Put your API key here!

    this.http
           .get(url)
           .subscribe((weatherData: any) => {
           console.log(weatherData);
           this.tampereTemp = weatherData.main.temp;
  });
  }

  loadHelsinki(){
    let url = 'http://api.openweathermap.org/data/2.5/weather?q=Helsinki'
            + '&units=metric'
            + '&lang=en'
            + ''; // Put your API key here!

    this.http
           .get(url)
           .subscribe((weatherData: any) => {
           console.log(weatherData);
           this.helsinkiTemp = weatherData.main.temp;
  });
  }

  onSearchLocationWithEvent(event: Event) {
       console.log('Control event value', (<HTMLInputElement>event.target).value);
       this.searchCity = (<HTMLInputElement>event.target).value;
       this.disabledForecastButton = false;
   }

  searchByCity(){
    console.log("searchCity value", this.searchCity);
    let url = 'http://api.openweathermap.org/data/2.5/weather?q='
            +  this.searchCity
            + '&units=metric'
            + '&lang=en'
            + ''; // Put your API key here!

    this.http
           .get(url)
           .subscribe((weatherData: any) => {
           console.log(weatherData);
           this.searchCityTemp = weatherData.main.temp;

    this.onResetControls();

  });
  }

  onResetControls() {
        this.disabledForecastButton = true;
  }

}
