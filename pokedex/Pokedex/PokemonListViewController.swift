import UIKit

class PokemonListViewController: UITableViewController, UISearchBarDelegate {
    
    @IBOutlet var searchBar1: UISearchBar!
    
    var pokemon: [PokemonListResult] = []
    var searchedPokemon: [PokemonListResult] = []
    var caughtPokemonListViewController: [String: Bool] = [:]
    
    func capitalize(text: String) -> String {
        return text.prefix(1).uppercased() + text.dropFirst()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        searchBar1.delegate = self
        
        
        
        //loads the data from pokemon API
        guard let url = URL(string: "https://pokeapi.co/api/v2/pokemon?limit=151") else {
            return
        }
        
        //urlsession targets data to be downloaded in the program
        URLSession.shared.dataTask(with: url) { (data, response, error) in
            guard let data = data else {
                return
            }
            //try and catch for the purpose of gettting a probable error from the api
            do {
                let entries = try JSONDecoder().decode(PokemonListResults.self, from: data)
                
                //this passes the data to the array of pokemons
                self.pokemon = entries.results
                self.searchedPokemon = self.pokemon
                
                for name in self.pokemon {
                    
                    self.caughtPokemonListViewController[name.name] = false
                    
                }
                
                print(self.caughtPokemonListViewController.count)
                
                DispatchQueue.main.async {
                    self.tableView.reloadData()
                }
            }
            catch let error {
                print(error)
            }
        }.resume()
        
        
    }
    
    func searchBar(_ searchBar: UISearchBar, textDidChange searchText: String) {
        DispatchQueue.main.async {
            if !searchText.isEmpty {
                self.searchedPokemon = self.pokemon.filter({ $0.name.contains(searchText.lowercased())})
                self.tableView.reloadData()
            } else {
                self.searchedPokemon = self.pokemon
                self.tableView.reloadData()
            }
        }
    }
    
    override func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    //gives the number of rows depending the number of elements in the array
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return searchedPokemon.count
    }
    
    //displays the data in the row
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        // takes a cell from the pool of cells in memory and adds it to the view table. The cell will be of identifier pokemoncell
        let cell = tableView.dequeueReusableCell(withIdentifier: "PokemonCell", for: indexPath)
        cell.textLabel?.text = capitalize(text: searchedPokemon[indexPath.row].name)
        return cell
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "ShowPokemonSegue",
                let destination = segue.destination as? PokemonViewController,
                let index = tableView.indexPathForSelectedRow?.row {
            destination.url = searchedPokemon[index].url
            destination.caughtPokemonViewController = caughtPokemonListViewController
            destination.descriptionName = searchedPokemon[index].name
        }
    }
}
