inherit ROOM;

void create()
{
        set("short", "��Ȫ");
        set("long", @LONG
�������ܶ��ڵĺ�԰��һ���ļ��������Ÿ�������Ļ�
�ݣ��������·����߲����޵Ĺ�ԡ���԰������һ̶�岨��̶
�в�ͣ��ð����Ȫ�������̶��������ȥ��
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"west" : __DIR__"hh_huayuan",
  		"east" : __DIR__"hh_xiaojing2",
	]));
        set("outdoors", "honghua");
        setup();
        replace_program(ROOM);
}
