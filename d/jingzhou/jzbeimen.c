inherit ROOM;

void create()
{
        set("short", "���ݱ���" );
        set("long", @LONG
�����Ǿ��ݵı��ţ����ھ����������Ǿ���Ҫ�أ���˳�
ǽ��ʵ�ޱȣ���¥�߸����������ڱ������⣬����ϡ�٣�����
���˲��࣬���Թٱ��ķ���Ҳ�Ͳ�ʮ�����ܡ�
LONG);
        set("objects", ([
                "/d/city/npc/bing" : 4,
                "/clone/npc/xunbu" : 1,
                "/d/beijing/npc/ducha" : 1,
        ]));
        set("exits", ([
        	"northup" :"/d/wudang/wdroad5",
	        "south" :__DIR__"beidajie2",
  
        ]));
        set("outdoors", "jingzhou");
        setup();
        replace_program(ROOM);
}

