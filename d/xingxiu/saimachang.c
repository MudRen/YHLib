inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������С����������������ھ���ά�����Ĺ���׷��
�ݡ�һ��С���ӿ�����һ�����ﲢ�����۵�һ���۷��㡣ȥ��
·��С���ӿ��ԶԹ����������������ʱ����������ñ��ӳ�
��С���ӡ���Ȼ�������ϲ�����С���ӣ���޾ͻ���Щ����
��Ļ�����С���Ӻ��ܵġ�
LONG);
        set("exits", ([ 
                "southeast" : __DIR__"beijiang",
        ]));

        set("objects", ([
                __DIR__"npc/alamuhan" : 1,
        ]));

        set("outdoors", "xiyu");

        setup();
        replace_program(ROOM);
}
