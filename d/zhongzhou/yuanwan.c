inherit ROOM;

void create()
{
        set("short", "��Ա�⸮ۡ");
        set("long", @LONG
���������ݸ�����Ա�⸮ۡ��ǰԺ��һ�����ǽ���ϻ�
�˸���ĵ��ĸ��֡��ƹ�ǽ�ſ��Ե���Ա���ǰ����������˵
��Ա�������ݳ������Ķ�ԡ�ûʲô�µĻ����ǲ�Ҫ��ȥΪ�
LONG);
        set("objects",([
                "/clone/quarry/gou2" : 2,
                __DIR__"npc/guanjia" : 1,
                __DIR__"npc/jiading" : 2,
        ]));
        set("exits", ([
  		"south" : __DIR__"yanlingdong1",
	]));
        set("outdoors", "zhongzhou");

        setup();
        replace_program(ROOM);
}
