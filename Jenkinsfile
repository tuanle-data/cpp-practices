pipeline {
    agent any

    stages {
        stage('Checkout and Build') {
            steps {
                git branch: 'main', url: 'https://github.com/tuanle-data/cpp-practices.git'
                bat 'docker build -t biarray-v1 .'
            }
        }
        stage('Run Docker Image') {
            steps {
                bat 'docker run biarray-v1:latest'
            }
        }
        stage('Clean up') {
            steps {
                bat '''
                    @echo off
                    for /f "tokens=*" %%i in ('docker ps -q') do docker stop %%i
                    for /f "tokens=*" %%i in ('docker ps -qa') do docker rm %%i
                    docker rmi biarray-v1:latest
                '''
            }
        }
    }
}