inherit ROOM;

void create()
{
	set("short","����Ȫ");
	set("long",@LONG
����Ȫ���Եø�������ʪ�󣬴����ĺ�����������˷���
���������£������У��������裬��ǧ����ֻ�ʵ�������һ��
ʹ�����û��Ž��ء��ر����ں���Ȫ�ϣ�˳���ǵ���������
����������һֻҧ��һֻ��β�����γ�ǧ�ٸ���������������
Ͷʯ��ɢ���������˾�̾����ۡ�
LONG);
	set("outdoors", "dali");
	set("exits", ([
	        "north"  : __DIR__"yuxuguanqian",
	        "east"   : __DIR__"xiaodao1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

