inherit ROOM;

void create()
{
          set("short","����");
          set("long",@LONG
����ͨ���ͷ��ĳ���,��Զ�����ǿͷ��ͳ����ˡ�
LONG);
          set("exits",([
            	  "west"     :__DIR__"chanyuan",
                  "south"    :__DIR__"songshan_chufang",
	          "east"     :__DIR__"kefang",
          ]));
          setup();
          replace_program(ROOM);
}