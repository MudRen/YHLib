inherit ROOM;

void create()
{
          set("short","����");
          set("long",@LONG
����ͨ���ͷ��ĳ���,��Զ�����ǿͷ��ͳ����ˡ�
LONG);
          set("exits",([
            	  "west"      :__DIR__"zhurongdian",
                  "northeast" :__DIR__"henshan_chufang",
	          "north"     :__DIR__"kefang",
          ]));

          set("objects", ([
                  __DIR__"npc/xiangke" : 2,
          ]));
          setup();
          replace_program(ROOM);
}