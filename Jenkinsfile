pipeline {
    agent any

    stages {
        stage('Checkout and Build') {
            steps {
                git 'https://github.com/tuanle-data/cpp-practices.git'
                bat 'docker build -t biarray-v1 .'
            }
        }
        stage('Run Docker Image') {
            steps {
                bat 'docker run biarray-v1:latest'
            }
        }
    }
}