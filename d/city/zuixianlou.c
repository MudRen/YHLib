inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
��Բ���������������ݳ�����¥����˵�����˲�֪������
������������ѧʿ���ε��ˣ�������¥�Ļ�����޲����ڣ���
ȻΪ�����ң�����һ�δ��麣�ڵļѻ����Ӵ�����¥��������
¥�²��ü��ף��˿Ͷ��ǴҴҵ����ˣ������ӡ����ȡ��׾�
�͸�·ȥ�ˡ�¥����������
LONG );
	set("exits", ([
		"east" : __DIR__"majiu",
		"west" : __DIR__"beidajie2",
		"up" : __DIR__"zuixianlou2",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
 
    set("no_fight", 1);
	setup();
	replace_program(ROOM);
}

