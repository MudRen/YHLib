inherit ROOM;

void create()
{
	set("short", "���⹱Ժ");
	set("long", @LONG
�������ţ��ֵ���һ������Ĵ�Ժ�������ʯʨ��������
����ϡ���Ժ�����������ɫ��ÿ����Ѯ���˴������о��˵�
�������ű�ǽ�������Ÿ�ʾ��
LONG);
	set("objects", ([
  		__DIR__"npc/zhukao3" : 1,
	]));
        set("no_clean_up", 0);
	set("exits", ([
  		"east" : __DIR__"road2",
	]));
        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
