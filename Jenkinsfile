pipeline {
    agent any

    environment {
        envProperties 'env.properties'
    }

    stages {
        stage('Checkout and Build') {
            steps {
                git branch: env.GIT_BRANCH, url: env.GIT_URL
                bat "docker build -t ${env.DOCKER_IMAGE_NAME}:${env.DOCKER_IMAGE_TAG} ."
            }
        }
        stage('Run Docker Image') {
            steps {
                bat "docker run ${env.DOCKER_IMAGE_NAME}:${env.DOCKER_IMAGE_TAG}"
            }
        }
        stage('Clean up') {
            steps {
                bat '''
                    @echo off
                    for /f "tokens=*" %%i in ('docker ps -q') do docker stop %%i
                    for /f "tokens=*" %%i in ('docker ps -qa') do docker rm %%i
                    for /f "tokens=*" %%i in ('docker images -q') do docker rmi %%i
                '''
            }
        }
    }
}