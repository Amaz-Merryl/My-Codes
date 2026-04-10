package EX4;

interface Shape
{
    // Constant for PI
    double PI = 3.14159;

    // Abstract methods
    double calculateArea();
    double calculateVolume();
}

class Sphere implements Shape
{
    double radius;

    Sphere(double radius)
    {
        this.radius = radius;
    }

    @Override
    public double calculateArea()
    {
        return 4 * PI * radius * radius;
    }

    @Override
    public double calculateVolume()
    {
        return (4.0 / 3.0) * PI * radius * radius * radius;
    }
}

// Cylinder class
class Cylinder implements Shape
{
    double radius, height;

    Cylinder(double radius, double height)
    {
        this.radius = radius;
        this.height = height;
    }

    @Override
    public double calculateArea()
    {
        // Surface area = 2r(h + r)
        return 2 * PI * radius * (height + radius);
    }

    @Override
    public double calculateVolume()
    {
        // Volume = rh
        return PI * radius * radius * height;
    }
}

// Cone class
class Cone implements Shape
{
    double radius, height;

    Cone(double radius, double height)
    {
        this.radius = radius;
        this.height = height;
    }

    @Override
    public double calculateArea()
    {
        // Surface area = r(l + r), where l = slant height
        double slantHeight = Math.sqrt(radius * radius + height * height);
        return PI * radius * (slantHeight + radius);
    }

    @Override
    public double calculateVolume()
    {
        // Volume = (1/3)rh
        return (1.0 / 3.0) * PI * radius * radius * height;
    }
}

// Main class to test
public class Shapes
{
    public static void main(String[] args)
    {
        Shape sphere = new Sphere(4);
        Shape cylinder = new Cylinder(8, 6);
        Shape cone = new Cone(2, 3);

        System.out.println("Sphere Area: " + sphere.calculateArea());
        System.out.println("Sphere Volume: " + sphere.calculateVolume());

        System.out.println("\nCylinder Area: " + cylinder.calculateArea());
        System.out.println("Cylinder Volume: " + cylinder.calculateVolume());

        System.out.println("\nCone Area: " + cone.calculateArea());
        System.out.println("Cone Volume: " + cone.calculateVolume());
    }
}
