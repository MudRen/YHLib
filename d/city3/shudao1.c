inherit ROOM;

void create()
{
        set("short", "��ʯ·" );
        set("long", @LONG
һ����ʯ�̳ɵ�·��ƽ̹������·�����档����������
���������˶�������ȥ�˳�����ЪЪ�ţ�һЩС��Ҳ�˻�����
�����ԺȵĶ�����
LONG);
        set("exits", ([
  		"east" : "/d/jingzhou/jzximen",
  		"west" : __DIR__"shudao2",
   	]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}

