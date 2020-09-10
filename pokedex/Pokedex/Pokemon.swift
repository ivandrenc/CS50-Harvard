import Foundation

struct PokemonListResults: Codable {
    let results: [PokemonListResult]
}

struct PokemonListResult: Codable {
    let name: String
    let url: String
}

struct PokemonResult: Codable {
    let id: Int
    let name: String
    let types: [PokemonTypeEntry]

}

struct PokemonTypeEntry: Codable {
    let slot: Int
    let type: PokemonType
}

struct PokemonType: Codable {
    let name: String
}

// structs for sprites

struct Images: Codable {
    let sprites: TypeOfImage
}

struct TypeOfImage: Codable {
    let front_default: String
}

// structs for description

struct Description: Codable {
    let flavor_text_entries: [Text]
}

struct Text: Codable {
    let flavor_text: String
    let language: Name
}

struct Name: Codable {
    let name: String
}
