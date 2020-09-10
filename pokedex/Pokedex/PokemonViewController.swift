import UIKit

class PokemonViewController: UIViewController {
    var url: String!
    var caughtPokemonViewController: [String:Bool] = [:]
    var namePokemon: String!
    var descriptionName: String!
    

    @IBOutlet var nameLabel: UILabel!
    @IBOutlet var numberLabel: UILabel!
    @IBOutlet var type1Label: UILabel!
    @IBOutlet var type2Label: UILabel!
    @IBOutlet var catchButton: UIButton!
    @IBOutlet weak var spriteImage: UIImageView!
    @IBOutlet weak var descriptionLabel: UILabel!
    
    
    let defaults = UserDefaults.standard
    
    

    func capitalize(text: String) -> String {
        return text.prefix(1).uppercased() + text.dropFirst()
    }
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        

        nameLabel.text = ""
        numberLabel.text = ""
        type1Label.text = ""
        type2Label.text = ""
        descriptionLabel.text = ""
        loadPokemon()
        loadDescription()
        
        
    }
    
   
    

    @IBAction func toggleCatch(_ sender: UIButton) {
        self.caughtPokemonViewController[self.namePokemon] = !self.caughtPokemonViewController[self.namePokemon]!
        saveCatch()
        checkSavedData()
        
        
    }
    
    func saveCatch() {
        defaults.set(self.caughtPokemonViewController[self.namePokemon], forKey: namePokemon)
    }
    
    func checkSavedData() {
        let changeInCaught = defaults.bool(forKey: namePokemon)
        
        if changeInCaught {
            catchButton.setTitle("Release", for: .normal)
            self.caughtPokemonViewController[self.namePokemon] = true
        }
        else {
            catchButton.setTitle("Catch it!", for: .normal)
            self.caughtPokemonViewController[self.namePokemon] = false
        }
    }
    
    
    
    func loadPokemon() {
        URLSession.shared.dataTask(with: URL(string: url)!) { (data, response, error) in
            guard let data = data else {
                return
            }

            do {
                let result = try JSONDecoder().decode(PokemonResult.self, from: data)
                
                
                DispatchQueue.main.async {
                    self.navigationItem.title = self.capitalize(text: result.name)
                    self.nameLabel.text = self.capitalize(text: result.name)
                    self.numberLabel.text = String(format: "#%03d", result.id)
                    self.namePokemon = result.name

                    for typeEntry in result.types {
                        if typeEntry.slot == 1 {
                            self.type1Label.text = typeEntry.type.name
                        }
                        else if typeEntry.slot == 2 {
                            self.type2Label.text = typeEntry.type.name
                        }
                        
                    }
                    
                    self.checkSavedData()
                
                }
                
                let sprite = try JSONDecoder().decode(Images.self, from: data)
                let urlImage = URL(string: sprite.sprites.front_default)
                let imageData = try Data(contentsOf: urlImage!)
                DispatchQueue.main.async {
                    self.spriteImage.image = UIImage(data: imageData)
                }
                
            }
            catch let error {
                print(error)
            }
            
            
            
        }.resume()
        
    }
    
    func loadDescription() {
        
        //loads the data from pokemon API
        guard let descriptionUrl = URL(string: "https://pokeapi.co/api/v2/pokemon-species/\(String(descriptionName))/") else {
            return
        }
        
        URLSession.shared.dataTask(with: descriptionUrl) { (data, response, error) in
            guard let data = data else {
                return
            }
            
            let pokemon: Description!
            
            do {
                let descriptionOfPokemon = try JSONDecoder().decode(Description.self, from: data)
                pokemon = descriptionOfPokemon
                for textEntry in pokemon.flavor_text_entries {
                    if textEntry.language.name == "en" {
                        DispatchQueue.main.async {
                            self.descriptionLabel.text = textEntry.flavor_text
                        }
                    }
                }
                
                
            }
            catch let error {
                print(error)
            }
        }.resume()
        
    }

}
