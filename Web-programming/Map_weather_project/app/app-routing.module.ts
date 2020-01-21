import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { CalendarComponent } from './calendar/calendar.component';
import { LoginComponent } from './login/login.component';
import { MapComponent } from './map/map.component';
import { RegisterComponent } from './register/register.component';
import { WeatherComponent } from './weather/weather.component';

const routes: Routes = [
  {
    path: 'map', component: MapComponent
  },
  {
    path: 'weather', component: WeatherComponent
  },
  {
    path: 'calendar', component: CalendarComponent
  },
  {
    path: 'login', component: LoginComponent
  },
  {
    path: 'register', component: RegisterComponent
  },
  {
    path: '', redirectTo: '/map', pathMatch: 'full'
  },
  {
    path: '**', component: MapComponent
  }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
