inherit ROOM;
void create()
{
	set("short", "�����ֹ�");
	set("long", @LONG
�����������ƾõ���ʷ���������³�ʫ����ʫ�꡹����
��ʯ�̡���گ������»Ȱʯ�̡������¡����������İ�����
�ס�������һ������������������д����ë�ʻ���ǩд��ֽ
��ײ��ϡ��������һ����ѧ��Ϊ�˴�д���ţ����ģ���Լ
�ȵȡ�
LONG);
	set("exits", ([
	    	"south"  : __DIR__"dahejieeast",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

