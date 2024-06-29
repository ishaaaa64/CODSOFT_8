def chatbot_response(user_input):
    # Convert the input to lowercase to make the comparison case-insensitive
    user_input = user_input.lower()

    # Predefined rules
    if "hello" in user_input or "hi" in user_input:
        return "Hello! How can I help you today?"
    elif "how are you" in user_input:
        return "I'm just a bot, but I'm doing great! How about you?"
    elif "your name" in user_input:
        return "I'm a simple chatbot created by GPT-4. What's your name?"
    elif "bye" in user_input or "goodbye" in user_input:
        return "Goodbye! Have a great day!"
    elif "help" in user_input:
        return "Sure, I'm here to help. What do you need assistance with?"
    else:
        return "I'm sorry, I don't understand that. Can you please rephrase?"

# Main loop to interact with the chatbot
def main():
    print("Welcome to the simple chatbot! Type 'exit' to end the conversation.")
    while True:
        user_input = input("You: ")
        if user_input.lower() == "exit":
            print("Chatbot: Goodbye! Have a great day!")
            break
        response = chatbot_response(user_input)
        print(f"Chatbot: {response}")

# Run the main loop
if __name__ == "__main__":
    main()
