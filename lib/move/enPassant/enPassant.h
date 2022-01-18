namespace chess
{
	
	class EnPassant : public Move
	{
	private:

	public:

		EnPassant(Point _start, Point _destination, color movingColor);

		~EnPassant() = default;

		virtual void execute_eat(Board& b) override;

	}

}