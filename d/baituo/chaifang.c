inherit ROOM;

void create()
{
  	set("short", "��");
        set("long", @LONG
���Ǽ䲻��Ĳ񷿣�ľ���Ѿ����չ��ˣ�ʣ��ļ��Ѹɲ�
���߰���ڷ��ڵ��棬ǽ�Ƿ���һ���񵶡�
LONG);
  	set("exits", ([
      		"west" : __DIR__"chufang",
  	]));
  	set("objects", ([
    		"/d/wudu/obj/ganchai"   : 2,
    		"/clone/weapon/chaidao" : 1,
  	]));
 	setup();
 	replace_program(ROOM);
}
