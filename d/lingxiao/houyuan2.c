inherit ROOM;

void create()
{
        set("short","��԰");
        set("long",@LONG 
�������ŵ��������������ϲ�����ľ����ˡ�һ�����Ҫ��
ûʲô�£��ǲ����������ġ��Ա߼������������дС�����
�Ͼ��Ե�����ѩ������֮�Σ�һ����÷������������֮�С�����
�����Χ�ֵĸ�ɫ÷�������Ǳ��з��飬����ǰ��򽣵ļң���
���Ƿ������ס����
LONG);
        set("outdoors", "lingxiao");
        set("exits",([
            	"south"  : __DIR__"houyuan1",  
            	"north"  : __DIR__"bridge", 
            	"west"  : __DIR__"qihan", 
            	"northwest"  : __DIR__"zoulang3", 
            	"northeast"  : __DIR__"zoulang4", 
            	"east"  : __DIR__"fenghuo", 
        ]));
        set("objects", ([ 
           	__DIR__"obj/mei" : 2, 
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

