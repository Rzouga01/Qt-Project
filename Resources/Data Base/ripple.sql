-- Create sequence for generating primary keys
CREATE SEQUENCE client_id_seq START WITH 1 INCREMENT BY 1;

-- Table structure for table 'clients'
CREATE TABLE clients (
  client_id INT PRIMARY KEY,
  email VARCHAR2(50) NOT NULL,
  first_name VARCHAR2(50) NOT NULL,
  last_name VARCHAR2(50) NOT NULL,
  address VARCHAR2(50) NOT NULL,
  phone_number VARCHAR2(8) NOT NULL,
  dob DATE NOT NULL
);

-- Create sequence for generating primary keys
CREATE SEQUENCE accident_id_seq START WITH 1 INCREMENT BY 1;

-- Table structure for table 'accidents'
CREATE TABLE accidents (
  accident_id INT PRIMARY KEY,
  client_id INT NOT NULL,
  type VARCHAR2(50) NOT NULL,
  damage INT NOT NULL,
  accident_date DATE NOT NULL,
  location VARCHAR2(50) NOT NULL,
  CONSTRAINT fk_client_id FOREIGN KEY (client_id) REFERENCES clients(client_id) ON DELETE CASCADE
);

-- Create sequence for generating primary keys
CREATE SEQUENCE contract_id_seq START WITH 1 INCREMENT BY 1;

-- Table structure for table 'contracts'
CREATE TABLE contracts (
  contract_id INT PRIMARY KEY,
  user_id INT NOT NULL,
  client_id INT NOT NULL,
  premium_amount INT NOT NULL,
  effective_date DATE NOT NULL,
  expiration_date DATE NOT NULL,
  payment_status INT NOT NULL,
  type VARCHAR2(50) NOT NULL,
  CONSTRAINT fk_user_id FOREIGN KEY (user_id) REFERENCES employees(user_id) ON DELETE CASCADE,
  CONSTRAINT fk_client_id_contract FOREIGN KEY (client_id) REFERENCES clients(client_id) ON DELETE CASCADE
);

-- Create sequence for generating primary keys
CREATE SEQUENCE user_id_seq START WITH 1 INCREMENT BY 1;

-- Table structure for table 'employees'
CREATE TABLE employees (
  user_id INT PRIMARY KEY,
  email VARCHAR2(50) NOT NULL,
  password VARCHAR2(50) NOT NULL,
  role INT NOT NULL,
  first_name VARCHAR2(50) NOT NULL,
  last_name VARCHAR2(50) NOT NULL,
  phone_number VARCHAR2(8) NOT NULL,
  address VARCHAR2(50) NOT NULL,
  dob DATE NOT NULL
);
