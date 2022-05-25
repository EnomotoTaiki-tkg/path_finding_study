#include "board.h"

//p���s����ꏊ�����ׂ�

bool Board::find(const Point& start, const Point& goal)
{
	getMass(start).setStatus(Mass::START);
	getMass(goal).setStatus(Mass::GOAL);

	Point p = start;
	while (p != goal) {
		Mass &m = getMass(p);
		Mass::status status = m.getStatus();
		if (p != start) m.setStatus(Mass::WAYPOINT);
		Point next;

		int diff_x = abs(p.x() - goal.x());//x�̍�
		int diff_y = abs(p.y() - goal.y());//y�̍�
		if (diff_x > diff_y) {
			if (p.x() < goal.x()) {
				p.setX(next.x() + 1); if (isValidated(next)) { p = next; continue; }
			}//�S�[�����E��������ΉE�Ɉړ�
			if (goal.x() < p.x()) { next.setX(p.x() - 1); if (isValidated(next)) { p = next; continue; } }//�����ɂ���΍��Ɉړ�
		}//��x����@�@��y����
		if (p.y() < goal.y()) { next.setY(p.y() + 1); if (isValidated(next)) { p = next; continue; } }//�㑤�Ȃ��
		if (goal.y() < p.y()) { next.setY(p.y() - 1); if (isValidated(next)) { p = next; continue; } }//�����Ȃ牺
	
		return false;

	}
	return true;
}
