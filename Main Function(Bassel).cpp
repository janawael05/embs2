int main() {
    addEvent(1, {"Concert", "Live music concert", "2024-12-01", "City Hall", 50.0, 100});
    addEvent(2, {"Workshop", "Tech workshop", "2024-11-25", "Tech Center", 30.0, 50});
    addEvent(3, {"Conference", "Business conference", "2024-11-30", "Convention Center", 100.0, 200});

    registerUser("bassel@example.com", "Bassel Shoeib");
    registerUser("kareem@example.com", "Kareem Tamer");

    displayEvents();

    bookEvent("bassel@example.com", 1);
    bookEvent("kareem@example.com", 2);

    viewBookings("bassel@example.com");

  
    searchEventsByKeyword("Tech");
    sortEventsByDate();

    return 0;
}
