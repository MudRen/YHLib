inherit ROOM;
 
void create()
{
        set("short", "�׻��ú���");
        set("long",@LONG
�����Ǻ�ľ�µĵڶ����ð׻��õĺ������ڡ�������ש��
�أ�����ȼ��Ѭ�㣬�ǳ��Ŀ���������������һ����һ����
���Ӻ�ü���ڵ��С�
LONG);
        set("exits", ([
            	"north" : __DIR__"baistep2",
        ]));
        set("objects", ([
                CLASS_D("riyue") + "/shangguan" : 1,
                __DIR__"npc/dizi4" : 4,
        ]));
        setup();
        replace_program(ROOM);
}
