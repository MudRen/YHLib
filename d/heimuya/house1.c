inherit ROOM;

void create()
{
  	set("short","����");
  	set("long",@LONG
����һ�����ŵ�С�ᣬ���ű���ŵ�һ��Ũ���Ļ��㡣��
�й���һ����Ů���ͼ�����������װ��Ů��Ŀ���⣬������
�ס����ﻹ��һ�Ų輸���������ӣ������������廨���棬��
����һ�ȶ�����ͨ�������
LONG);
        set("exits", ([
                "south" : __DIR__"huoting",
        ]));
        if (random(10) == 1)
        {
              set("objects", ([
                      "/kungfu/class/riyue/dongfang/dongfang" : 1,
              ]));
        }
        else
              set("objects", ([
                       __DIR__"npc/shinu" : 1,
              ]));
 

        setup();
        replace_program(ROOM);
}
