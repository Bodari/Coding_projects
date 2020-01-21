package com.example.memokotlin

import android.content.ContentValues
import android.os.Bundle
import android.view.View
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity

// Kotlin
import kotlinx.android.synthetic.main.activity_add_new_note.*

class AddNewNoteActivity : AppCompatActivity() {

    private var id = 0

    // Vaihda menu-näkymä & Muokkauksessa tuo edellisen muistion tekstit näkyviin.
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_add_new_note)

        try {
            val bundle:Bundle = intent.extras
            id = bundle.getInt("ID", 0)
            if (id!=0){
                titleEt.setText(bundle.getString("name"))
                descEt.setText(bundle.getString("des"))
            }
        }catch (ex:Exception){}
    }

    // Lisää tai muokkaa nykyistä muistiota.
    fun addOrEditNote(view:View){
        var dbManager = DatabaseManager(this)

        var values = ContentValues()
        values.put("Title", titleEt.text.toString())
        values.put("Description", descEt.text.toString())

        if (id ==0){
            val ID = dbManager.insert(values)
            if (ID>0){
                Toast.makeText(this, "Muistio lisätty.", Toast.LENGTH_SHORT).show()
                finish()
            }
            else{
                Toast.makeText(this, "Tapahtui virhe...", Toast.LENGTH_SHORT).show()
            }
        }
        else{
            var selectionArgs = arrayOf(id.toString())
            val ID = dbManager.update(values, "ID=?", selectionArgs)
            if (ID>0){
                Toast.makeText(this, "Muokkaus tallennettu.", Toast.LENGTH_SHORT).show()
                finish()
            }
            else{
                Toast.makeText(this, "Tapahtui virhe...", Toast.LENGTH_SHORT).show()
            }
        }
    }
}
