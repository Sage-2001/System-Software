import React from "react";

function header(props) {
  return (
    <div>
      <nav class="navbar navbar-expand-lg">
        <div class="container">
          <a class="navbar-brand" href="#">
            Amazon
          </a>
          <button
            class="navbar-toggler"
            type="button"
            data-bs-toggle="collapse"
            data-bs-target="#navbarNav"
            aria-controls="navbarNav"
            aria-expanded="false"
            aria-label="Toggle navigation"
          >
            <span class="navbar-toggler-icon"></span>
          </button>
          <div class="collapse navbar-collapse" id="navbarNav">
            <ul class="navbar-nav ms-auto">
              <li class="nav-item">
                <a class="nav-link" href="#">
                  Home
                </a>
              </li>
              <li class="nav-item">
                <a class="nav-link" href="#">
                  Groceries
                </a>
              </li>
              <li class="nav-item">
                <a class="nav-link" href="#">
                  Clothes
                </a>
              </li>
              <li class="nav-item">
                <a class="nav-link" href="#">
                  Utensils
                </a>
              </li>
              <li class="nav-item">
                <a class="nav-link" href="#">
                  Electronic Items
                </a>
              </li>
              <li class="nav-item">
                <a class="nav-link" href="#">
                  User
                </a>
              </li>
            </ul>
            <form class="d-flex">
              <input
                class="form-control me-2"
                type="search"
                placeholder="Search"
                aria-label="Search"
              />
              <button class="btn btn-outline-success" type="submit">
                Search
              </button>
            </form>
          </div>
        </div>
      </nav>
    </div>
  );
}

export default header;
