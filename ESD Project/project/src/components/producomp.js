import React from "react";
import * as styles from "../style/product_listing.css";

function producomp(props) {
  return (
    <div>
      <div class="col-lg-3 col-md-4 col-sm-6">
        <div class="product-card">
          <img src="product-image.jpg" alt="Product Name" />
          <h3 class="product-title">Product Name</h3>
          <p class="product-description">Product description goes here.</p>
          <p class="product-price">$10.00</p>
          <button type="button" class="btn btn-primary">
            Buy
          </button>
        </div>
      </div>
    </div>
  );
}

export default producomp;
