inherit ROOM;

void create()
{
        set("short", "��ɽ");
        set("long", @LONG
�������ܶ��ڵĺ�԰��һ���ļ��������Ÿ�������Ļ�
�ݣ��������·����߲����޵Ĺ�ԡ���԰����������һ����ɽ
����̦�����ǣ��������㡣
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"east" : __DIR__"hh_huayuan",
  		"west" : __DIR__"hh_xiaojing1",
	]));
        set("outdoors", "honghua");
        setup();
        replace_program(ROOM);
}
